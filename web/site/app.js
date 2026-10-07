// Image Processing Lab: UI glue around the C++/WebAssembly core (dip.js).
import createDipModule from './dip.js';

let dip;

// ------------------------------------------------------------ helpers ---

function el(tag, attrs = {}, ...children) {
  const node = document.createElement(tag);
  for (const [k, v] of Object.entries(attrs)) {
    if (k === 'class') node.className = v;
    else if (k.startsWith('on')) node.addEventListener(k.slice(2), v);
    else if (v !== false && v != null) node.setAttribute(k, v === true ? '' : v);
  }
  for (const c of children.flat()) node.append(c instanceof Node ? c : document.createTextNode(c));
  return node;
}

// Run `fn` on the next animation frame, coalescing bursts of slider input.
function coalesce(fn) {
  let queued = false;
  let running = false;
  const tick = async () => {
    queued = false;
    running = true;
    try { await fn(); } catch (e) { console.error(e); }
    running = false;
    if (queued) requestAnimationFrame(tick);
  };
  return () => {
    if (queued) return;
    queued = true;
    if (!running) requestAnimationFrame(tick);
  };
}

function timed(meta, fn) {
  const t0 = performance.now();
  const result = fn();
  meta.textContent = `${(performance.now() - t0).toFixed(1)} ms`;
  return result;
}

// ------------------------------------------------------------ samples ---

const SAMPLES = {
  lisa: ['LISA.64', 'samples/LISA.64'],
  lincoln: ['LINCOLN.64', 'samples/LINCOLN.64'],
  jet: ['JET.64', 'samples/JET.64'],
  liberty: ['LIBERTY.64', 'samples/LIBERTY.64'],
  olympics: ['Doodle', 'samples/olympics.jpg'],
  plant: ['Plant & fence', 'samples/plant-fence.jpg'],
  parts: ['Mechanical parts', 'samples/mechanical-parts.jpg'],
  square: ['White square', 'samples/square.png'],
  campus: ['Campus', 'samples/campus.jpg'],
  squares: ['Hidden squares', 'samples/hidden-squares.png'],
  moon: ['Moon', 'samples/moon.jpg'],
  testPattern: ['Test pattern', 'samples/test-pattern.png'],
  text: ['Text', 'samples/text-pattern.png'],
  portrait: ['Portrait', 'samples/portrait.jpg'],
  scan: ['Gray scan', 'samples/scan.png'],
  balloons: ['Balloons', 'samples/balloons.jpg'],
  dog: ['Dog', 'samples/dog.jpg'],
  mri1: ['MRI slice 1', 'samples/mri-1.jpg'],
  mri2: ['MRI slice 2', 'samples/mri-2.jpg'],
  totem: ['Totem poles', 'samples/totem-poles.jpg'],
};

const MAX_UPLOAD = 1024;
const cache = new Map();

function imageToData(img, maxDim) {
  const scale = Math.min(1, maxDim / Math.max(img.width, img.height));
  const w = Math.max(1, Math.round(img.width * scale));
  const h = Math.max(1, Math.round(img.height * scale));
  const c = document.createElement('canvas');
  c.width = w;
  c.height = h;
  const ctx = c.getContext('2d', { willReadFrequently: true });
  ctx.drawImage(img, 0, 0, w, h);
  return ctx.getImageData(0, 0, w, h);
}

async function decodeImage(blob, maxDim) {
  const bitmap = await createImageBitmap(blob);
  const data = imageToData(bitmap, maxDim);
  bitmap.close?.();
  return data;
}

async function loadSample(key) {
  if (!cache.has(key)) {
    const url = SAMPLES[key][1];
    cache.set(key, (async () => {
      const res = await fetch(url);
      if (!res.ok) throw new Error(`${url}: ${res.status}`);
      if (url.endsWith('.64')) return dip.decode64(await res.text());
      return decodeImage(await res.blob(), MAX_UPLOAD);
    })());
  }
  return cache.get(key);
}

async function loadFile(file) {
  if (file.name.toLowerCase().endsWith('.64')) return dip.decode64(await file.text());
  return decodeImage(file, MAX_UPLOAD);
}

// ---------------------------------------------------------- components ---

function drawTo(canvas, img) {
  canvas.width = img.width;
  canvas.height = img.height;
  canvas.classList.toggle('pixelated', img.width <= 160 && img.height <= 160);
  canvas.getContext('2d').putImageData(new ImageData(img.data, img.width, img.height), 0, 0);
}

function cssVar(name) {
  return getComputedStyle(document.documentElement).getPropertyValue(name).trim();
}

function drawHistogram(canvas, counts) {
  const dpr = window.devicePixelRatio || 1;
  const w = canvas.clientWidth || 260;
  const h = canvas.clientHeight || 90;
  canvas.width = Math.round(w * dpr);
  canvas.height = Math.round(h * dpr);
  const ctx = canvas.getContext('2d');
  ctx.scale(dpr, dpr);
  ctx.clearRect(0, 0, w, h);

  const n = counts.length;
  let max = 0;
  for (const c of counts) max = Math.max(max, c);
  const base = h - 14;
  ctx.strokeStyle = cssVar('--border');
  ctx.beginPath();
  ctx.moveTo(0, base + 0.5);
  ctx.lineTo(w, base + 0.5);
  ctx.stroke();

  ctx.fillStyle = cssVar('--accent');
  const bw = w / n;
  for (let i = 0; i < n; i++) {
    if (!counts[i]) continue;
    const bh = Math.max(1, (counts[i] / max) * (base - 4));
    ctx.fillRect(i * bw, base - bh, Math.max(1, bw - (n <= 64 ? 1 : 0)), bh);
  }
  ctx.fillStyle = cssVar('--muted');
  ctx.font = '10px system-ui, sans-serif';
  ctx.textBaseline = 'bottom';
  ctx.textAlign = 'left';
  ctx.fillText('0', 0, h);
  ctx.textAlign = 'right';
  ctx.fillText(String(n - 1), w, h);
  ctx.textAlign = 'center';
  ctx.fillText(`max ${max}`, w / 2, h);
}

// A figure: image canvas, caption and an optional histogram.
function figure(title, { hist = 0 } = {}) {
  const canvas = el('canvas');
  const caption = el('figcaption', {}, el('strong', {}, title));
  const note = el('span');
  caption.append(' ', note);
  const histCanvas = hist ? el('canvas', { class: 'hist' }) : null;
  const node = el('figure', {}, el('div', { class: 'view' }, canvas), caption, histCanvas || []);
  return {
    el: node,
    show(img, text) {
      drawTo(canvas, img);
      note.textContent = text ?? `${img.width}×${img.height}`;
      if (histCanvas) drawHistogram(histCanvas, dip.histogram(img, hist));
    },
  };
}

function slider(label, { min, max, step = 1, value, format = (v) => v }, onInput) {
  const input = el('input', { type: 'range', min, max, step, value });
  const output = el('output', {}, format(+value));
  input.addEventListener('input', () => {
    output.textContent = format(+input.value);
    onInput?.();
  });
  return {
    el: el('div', { class: 'control' }, el('label', {}, label, output), input),
    get value() { return +input.value; },
  };
}

function selectBox(label, options, value, onChange) {
  const select = el('select', { onchange: () => onChange?.() },
    options.map(([v, text]) => el('option', { value: v, selected: v === value }, text)));
  return {
    el: el('div', { class: 'control' }, el('label', {}, label), select),
    get value() { return select.value; },
  };
}

function segmented(label, options, value, onChange) {
  let current = value;
  const buttons = options.map(([v, text]) => el('button', {
    type: 'button',
    class: v === value ? 'on' : '',
    onclick: () => {
      current = v;
      buttons.forEach((b, i) => b.classList.toggle('on', options[i][0] === v));
      onChange?.();
    },
  }, text));
  return {
    el: el('div', { class: 'control' }, el('label', {}, label), el('div', { class: 'segmented' }, buttons)),
    get value() { return current; },
  };
}

function checkbox(label, checked, onChange) {
  const input = el('input', { type: 'checkbox', checked, onchange: () => onChange?.() });
  return {
    el: el('div', { class: 'control check' }, el('label', {}, input, label)),
    get value() { return input.checked; },
  };
}

// Sample selector + "upload your own" button. Calls onChange(imageData).
function sourcePicker(label, keys, onChange, { accept = 'image/*' } = {}) {
  let current = null;
  const fileName = 'upload';
  const options = keys.map((k) => [k, SAMPLES[k][0]]);
  const select = el('select', {}, options.map(([v, t]) => el('option', { value: v }, t)));
  const fileInput = el('input', { type: 'file', accept });
  const set = async (promise) => {
    try {
      current = await promise;
      onChange(current);
    } catch (e) {
      console.error(e);
      alert(`Could not load image: ${e.message}`);
    }
  };
  select.addEventListener('change', () => {
    if (select.value !== fileName) set(loadSample(select.value));
  });
  fileInput.addEventListener('change', () => {
    const file = fileInput.files[0];
    if (!file) return;
    if (!select.querySelector(`option[value="${fileName}"]`)) select.append(el('option', { value: fileName }, 'Uploaded image'));
    select.value = fileName;
    set(loadFile(file));
    fileInput.value = '';
  });
  return {
    el: el('div', { class: 'control' }, el('label', {}, label),
      el('div', { style: 'display:flex;gap:6px' }, select,
        el('label', { class: 'file-btn', title: 'Use your own image' }, 'Upload…', fileInput))),
    get image() { return current; },
    load() { return set(loadSample(keys[0])); },
  };
}

function panel(section, title, description) {
  const meta = el('span', { class: 'meta' });
  const controls = el('div', { class: 'controls' });
  const grid = el('div', { class: 'grid' });
  section.append(el('div', { class: 'panel' },
    el('div', { class: 'panel-head' }, el('h3', {}, title), meta),
    description ? el('p', { class: 'panel-desc' }, description) : [],
    controls, grid));
  return {
    meta, grid,
    add(...items) { controls.append(...items.map((i) => i.el ?? i)); },
    figures(...figs) { grid.append(...figs.map((f) => f.el)); return figs; },
  };
}

// --------------------------------------------- 01 gray levels & histogram ---

function initLevels(section) {
  const p = panel(section, 'Histogram & arithmetic operations',
    'Values are clamped to the 32 gray levels [0, 31]. Upload any image to convert it to 32 levels.');
  const [orig, add, mul, avg, diff] = p.figures(
    figure('Original', { hist: 32 }),
    figure('Add / subtract', { hist: 32 }),
    figure('Multiply', { hist: 32 }),
    figure('Average of two images', { hist: 32 }),
    figure('Difference g(x,y) = f(x,y) − f(x−1,y)', { hist: 32 }),
  );
  const update = coalesce(() => {
    const a = src.image && dip.quantize32(src.image);
    const b = src2.image && dip.quantize32(src2.image);
    if (!a) return;
    timed(p.meta, () => {
      orig.show(a);
      add.show(dip.addConstant(a, addS.value), `c = ${addS.value > 0 ? '+' : ''}${addS.value}`);
      mul.show(dip.multiplyConstant(a, mulS.value), `× ${mulS.value}`);
      if (b) avg.show(dip.averageImages(a, b));
      diff.show(dip.differenceX(a));
    });
  });
  const src = sourcePicker('Image', ['lisa', 'jet', 'liberty', 'lincoln'], update, { accept: '.64,image/*' });
  const src2 = sourcePicker('Second image (average)', ['lincoln', 'lisa', 'jet', 'liberty'], update, { accept: '.64,image/*' });
  const addS = slider('Add constant', { min: -31, max: 31, value: 4 }, update);
  const mulS = slider('Multiply by', { min: 0, max: 8, step: 0.25, value: 2 }, update);
  p.add(src, src2, addS, mulS);
  return Promise.all([src.load(), src2.load()]);
}

// --------------------------------------------------------- 02 enhancement ---

function initEnhance(section) {
  const p = panel(section, 'Grayscale, threshold, resampling, brightness / contrast, equalization');
  const figs = p.figures(
    figure('Original', { hist: 256 }),
    figure('Grayscale', { hist: 256 }),
    figure('Binary threshold', { hist: 256 }),
    figure('Resampled (bilinear)', { hist: 256 }),
    figure('Gray-level reduction', { hist: 256 }),
    figure('Brightness & contrast', { hist: 256 }),
    figure('Histogram equalization', { hist: 256 }),
  );
  const [orig, gray, bin, resized, levels, bc, eq] = figs;
  const update = coalesce(() => {
    const im = src.image;
    if (!im) return;
    timed(p.meta, () => {
      orig.show(im);
      const mode = grayMode.value;
      const g = mode === 'A' ? dip.grayAverage(im) : mode === 'B' ? dip.grayWeighted(im) : dip.grayDifference(im);
      gray.show(g, mode === 'A' ? '(R+G+B)/3' : mode === 'B' ? '0.299R+0.587G+0.114B' : '|A − B|');
      const base = mode === 'diff' ? dip.grayWeighted(im) : g;
      bin.show(dip.threshold(base, thr.value), `T = ${thr.value}`);
      resized.show(dip.scaleImage(base, scale.value));
      levels.show(dip.quantize(base, lv.value), `${lv.value} levels`);
      bc.show(dip.brightnessContrast(base, bright.value, contrast.value),
        `b = ${bright.value}, c = ${contrast.value}`);
      eq.show(dip.equalize(base));
    });
  });
  const src = sourcePicker('Image', ['olympics', 'plant', 'portrait', 'moon'], update);
  const grayMode = segmented('Grayscale', [['A', 'A: average'], ['B', 'B: weighted'], ['diff', '|A − B|']], 'B', update);
  const thr = slider('Threshold', { min: 0, max: 255, value: 128 }, update);
  const scale = slider('Scale %', { min: 10, max: 300, value: 50, format: (v) => `${v}%` }, update);
  const lv = slider('Gray levels', { min: 2, max: 64, value: 8 }, update);
  const bright = slider('Brightness', { min: -128, max: 128, value: 0 }, update);
  const contrast = slider('Contrast', { min: 0, max: 3, step: 0.05, value: 1.5 }, update);
  p.add(src, grayMode, thr, scale, lv, bright, contrast);
  return src.load();
}

// --------------------------------------------------- 03 spatial filtering ---

function initSpatial(section) {
  // Mask filters.
  const p1 = panel(section, 'Spatial filters', 'Mask size affects both the result and the computation time (shown top-right).');
  const [orig1, out1] = p1.figures(figure('Original'), figure('Filtered'));
  const update1 = coalesce(() => {
    const im = src1.image;
    if (!im) return;
    orig1.show(im);
    const size = mask.value;
    const kind = filter.value;
    const res = timed(p1.meta, () =>
      kind === 'smooth' ? dip.smooth(im, size)
        : kind === 'sharpen' ? dip.sharpen(im, size, coef.value)
          : kind === 'median' ? dip.median(im, size)
            : dip.sobel(im));
    out1.show(res, kind === 'sobel' ? 'Sobel |∇f|' : kind === 'sharpen'
      ? `${size}×${size}, coefficient ${coef.value}` : `${size}×${size}`);
  });
  const src1 = sourcePicker('Image', ['campus', 'plant', 'parts', 'square'], update1);
  const filter = segmented('Filter', [['smooth', 'Smoothing'], ['sharpen', 'Sharpening'], ['median', 'Median'], ['sobel', 'Sobel']], 'smooth', update1);
  const mask = slider('Mask size', { min: 1, max: 31, step: 2, value: 7, format: (v) => `${v}×${v}` }, update1);
  const coef = slider('Sharpen coefficient', { min: 0, max: 10, step: 0.5, value: 3 }, update1);
  p1.add(src1, filter, mask, coef);

  // Marr-Hildreth.
  const p2 = panel(section, 'Marr-Hildreth edge detection',
    'Gaussian smoothing + Laplacian (LoG), then zero crossings stronger than the threshold.');
  const [orig2, out2] = p2.figures(figure('Original'), figure('Zero crossings'));
  const update2 = coalesce(() => {
    const im = src2.image;
    if (!im) return;
    orig2.show(im);
    out2.show(timed(p2.meta, () => dip.marrHildreth(im, ksize.value, sigma.value, zt.value)),
      `σ = ${sigma.value}, ${ksize.value}×${ksize.value}, threshold ${zt.value}%`);
  });
  const src2 = sourcePicker('Image', ['parts', 'campus', 'square', 'plant'], update2);
  const sigma = slider('σ', { min: 0.5, max: 5, step: 0.25, value: 2 }, update2);
  const ksize = slider('Kernel size', { min: 3, max: 31, step: 2, value: 13 }, update2);
  const zt = slider('Zero-crossing threshold', { min: 0, max: 30, step: 0.5, value: 4, format: (v) => `${v}%` }, update2);
  p2.add(src2, sigma, ksize, zt);

  // Local enhancement.
  const p3 = panel(section, 'Local enhancement vs. histogram equalization',
    'Enhance g = C·f where k₀·m_G ≤ m_Sxy ≤ k₁·m_G and k₂·σ_G ≤ σ_Sxy ≤ k₃·σ_G.');
  const [orig3, local, histEq] = p3.figures(
    figure('Original', { hist: 256 }), figure('Local enhancement', { hist: 256 }), figure('Histogram equalization', { hist: 256 }));
  const update3 = coalesce(() => {
    const im = src3.image;
    if (!im) return;
    orig3.show(im);
    local.show(timed(p3.meta, () => dip.localEnhancement(im, sxy.value, k0.value, k1.value, k2.value, k3.value, C.value)),
      `Sxy = ${sxy.value}×${sxy.value}`);
    histEq.show(dip.equalize(im));
  });
  const src3 = sourcePicker('Image', ['squares', 'moon'], update3);
  const sxy = slider('Neighborhood Sxy', { min: 1, max: 81, step: 2, value: 3, format: (v) => `${v}×${v}` }, update3);
  const k0 = slider('k₀', { min: 0, max: 2, step: 0.05, value: 0 }, update3);
  const k1 = slider('k₁', { min: 0, max: 2, step: 0.05, value: 0.25 }, update3);
  const k2 = slider('k₂', { min: 0, max: 2, step: 0.01, value: 0 }, update3);
  const k3 = slider('k₃', { min: 0, max: 2, step: 0.01, value: 0.1 }, update3);
  const C = slider('C', { min: 1, max: 40, step: 0.5, value: 20 }, update3);
  p3.add(src3, sxy, k0, k1, k2, k3, C);

  return Promise.all([src1.load(), src2.load(), src3.load()]);
}

// --------------------------------------------------- 04 frequency domain ---

function initFrequency(section) {
  const shapeNames = ['Ideal', 'Butterworth', 'Gaussian'];

  const p1 = panel(section, 'Fourier transform (FFT)', 'Spectrum: G·[log(1+|F|) − F_min] / [F_max − F_min], centered.');
  const [orig1, mag, phase, inv] = p1.figures(figure('Original'), figure('Spectrum'), figure('Phase angle'), figure('IDFT'));
  const update1 = coalesce(() => {
    const im = src1.image;
    if (!im) return;
    orig1.show(im);
    const s = timed(p1.meta, () => dip.spectrum(im));
    mag.show(s.magnitude);
    phase.show(s.phase);
    inv.show(s.inverse);
  });
  const src1 = sourcePicker('Image', ['testPattern', 'text', 'campus'], update1);
  p1.add(src1);

  const p2 = panel(section, 'Low-pass & high-pass filters');
  const [low, high] = p2.figures(figure('Low-pass'), figure('High-pass'));
  const update2 = coalesce(() => {
    const im = src2.image;
    if (!im) return;
    const shape = +shape2.value;
    timed(p2.meta, () => {
      low.show(dip.frequencyFilter(im, shape, cut.value, false, order.value), `${shapeNames[shape]}, D₀ = ${cut.value}`);
      high.show(dip.frequencyFilter(im, shape, cut.value, true, order.value), `${shapeNames[shape]}, D₀ = ${cut.value}`);
    });
  });
  const src2 = sourcePicker('Image', ['testPattern', 'text', 'campus'], update2);
  const shape2 = segmented('Filter', shapeNames.map((n, i) => [String(i), n]), '0', update2);
  const cut = slider('Cut-off D₀', { min: 1, max: 200, value: 30 }, update2);
  const order = slider('Butterworth order', { min: 1, max: 10, value: 2 }, update2);
  p2.add(src2, shape2, cut, order);

  const p3 = panel(section, 'Homomorphic filter', 'H(u,v) = (γH − γL)[1 − e^(−c·D²/D₀²)] + γL applied to log(1 + f).');
  const [orig3, homo] = p3.figures(figure('Original'), figure('Homomorphic'));
  const update3 = coalesce(() => {
    const im = src3.image;
    if (!im) return;
    orig3.show(im);
    homo.show(timed(p3.meta, () => dip.homomorphic(im, gH.value, gL.value, d0.value, c.value)),
      `γH ${gH.value}, γL ${gL.value}, D₀ ${d0.value}`);
  });
  const src3 = sourcePicker('Image', ['campus', 'testPattern', 'moon'], update3);
  const gH = slider('γH', { min: 0.5, max: 4, step: 0.1, value: 2 }, update3);
  const gL = slider('γL', { min: 0, max: 1.5, step: 0.05, value: 0.5 }, update3);
  const d0 = slider('D₀', { min: 1, max: 200, value: 30 }, update3);
  const c = slider('c', { min: 0.1, max: 5, step: 0.1, value: 1 }, update3);
  p3.add(src3, gH, gL, d0, c);

  const p4 = panel(section, 'Motion blur restoration',
    'The image is blurred with a linear motion PSF (plus optional noise), then restored in the frequency domain.');
  const [orig4, blurred, restored] = p4.figures(figure('Original'), figure('Motion blurred'), figure('Restored'));
  const update4 = coalesce(() => {
    const im = src4.image;
    if (!im) return;
    orig4.show(im);
    const wiener = method.value === '1';
    const param = wiener ? Math.pow(10, kexp.value) : radius.value;
    const r = timed(p4.meta, () => dip.restore(im, len.value, angle.value, noise.value, +method.value, param));
    blurred.show(r.blurred, `length ${len.value}, ${angle.value}°, σ ${noise.value}`);
    restored.show(r.restored, wiener ? `Wiener, K = ${param.toExponential(1)}` : `Inverse, radius ${radius.value || '∞'}`);
  });
  const src4 = sourcePicker('Image', ['text', 'testPattern', 'campus'], update4);
  const len = slider('Blur length', { min: 1, max: 60, value: 20 }, update4);
  const angle = slider('Angle', { min: 0, max: 180, value: 45, format: (v) => `${v}°` }, update4);
  const noise = slider('Noise σ', { min: 0, max: 20, step: 0.5, value: 0 }, update4);
  const method = segmented('Method', [['0', 'Inverse'], ['1', 'Wiener']], '1', update4);
  const radius = slider('Inverse radius (0 = none)', { min: 0, max: 300, value: 0 }, update4);
  const kexp = slider('Wiener K (log₁₀)', { min: -6, max: 0, step: 0.25, value: -3 }, update4);
  p4.add(src4, len, angle, noise, method, radius, kexp);

  return Promise.all([src1.load(), src2.load(), src3.load(), src4.load()]);
}

// ------------------------------------------------------------- 05 color ---

function initColor(section) {
  const p1 = panel(section, 'Color model conversion');
  const models = ['CMY', 'HSI', 'XYZ', 'Lab', 'YUV'];
  const [orig1, ...modelFigs] = p1.figures(figure('RGB'), ...models.map((m) => figure(m === 'Lab' ? 'L*a*b*' : m)));
  const update1 = coalesce(() => {
    const im = src1.image;
    if (!im) return;
    orig1.show(im);
    timed(p1.meta, () => models.forEach((m, i) => modelFigs[i].show(dip.colorModel(im, m))));
  });
  const src1 = sourcePicker('Image', ['portrait', 'balloons', 'dog'], update1);
  p1.add(src1);

  const p2 = panel(section, 'Pseudo-color', 'Gray levels mapped through a color table; the bar shows gray 0 → 255.');
  const maps = ['Autumn', 'Bone', 'Jet', 'Winter', 'Rainbow', 'Hot'];
  const [gray2, pseudo] = p2.figures(figure('Grayscale'), figure('Pseudo-color'));
  const bar = el('canvas', { class: 'bar' });
  pseudo.el.append(bar);
  const update2 = coalesce(() => {
    const im = src2.image;
    if (!im) return;
    const map = +map2.value;
    gray2.show(dip.grayWeighted(im));
    pseudo.show(timed(p2.meta, () => dip.pseudoColor(im, map)), maps[map]);
    drawTo(bar, dip.colorBar(map, 256, 1));
  });
  const src2 = sourcePicker('Image', ['scan', 'moon', 'mri1'], update2);
  const map2 = selectBox('Color map', maps.map((m, i) => [String(i), m]), '2', update2);
  p2.add(src2, map2);

  const p3 = panel(section, 'K-means color segmentation', 'Every pixel is replaced by the color of its cluster center.');
  const [orig3, seg] = p3.figures(figure('Original'), figure('Segmented'));
  const spaces = ['RGB', 'HSI', 'L*a*b*'];
  const update3 = coalesce(() => {
    const im = src3.image;
    if (!im) return;
    orig3.show(im);
    seg.show(timed(p3.meta, () => dip.kmeans(im, k.value, +space.value)), `k = ${k.value}, ${spaces[+space.value]}`);
  });
  const src3 = sourcePicker('Image', ['balloons', 'portrait', 'dog'], update3);
  const k = slider('k', { min: 2, max: 50, value: 2 }, update3);
  const space = segmented('Color space', spaces.map((s, i) => [String(i), s]), '0', update3);
  p3.add(src3, k, space);

  return Promise.all([src1.load(), src2.load(), src3.load()]);
}

// ---------------------------------------------------------- 06 geometry ---

function initGeometry(section) {
  const p1 = panel(section, 'Geometric transformation');
  const [orig1, fish, kal, wav, spi, rip] = p1.figures(
    figure('Original'), figure('Fisheye'), figure('Kaleidoscope'), figure('Wavy'), figure('Spiral'), figure('Ripple'));
  const update1 = coalesce(() => {
    const im = src1.image;
    if (!im) return;
    orig1.show(im);
    timed(p1.meta, () => {
      fish.show(dip.warp(im, 'fisheye', fishS.value, 0), `strength ${fishS.value}`);
      kal.show(dip.warp(im, 'kaleidoscope', segs.value, 0), `${segs.value} segments`);
      wav.show(dip.warp(im, 'wavy', amp.value, freq.value), `amplitude ${amp.value}`);
      spi.show(dip.warp(im, 'spiral', twist.value / 1000, 0), `twist ${twist.value / 1000}`);
      rip.show(dip.warp(im, 'ripple', amp.value, freq.value), `amplitude ${amp.value}`);
    });
  });
  const src1 = sourcePicker('Image', ['dog', 'totem', 'balloons'], update1);
  const fishS = slider('Fisheye strength', { min: 0.5, max: 8, step: 0.25, value: 3 }, update1);
  const segs = slider('Kaleidoscope segments', { min: 2, max: 32, value: 16 }, update1);
  const amp = slider('Wave amplitude', { min: 0, max: 40, value: 20 }, update1);
  const freq = slider('Wave frequency', { min: 0.01, max: 0.4, step: 0.01, value: 0.1 }, update1);
  const twist = slider('Spiral twist (×10⁻³)', { min: -30, max: 30, value: 10 }, update1);
  p1.add(src1, fishS, segs, amp, freq, twist);

  const p2 = panel(section, 'Image fusion with the wavelet transform',
    'Haar DWT: average the LL band, keep the larger-magnitude detail coefficient, then reconstruct.');
  const [a2, b2, fused, bands] = p2.figures(figure('Image A'), figure('Image B'), figure('Fused'), figure('Fused sub-bands'));
  const update2 = coalesce(() => {
    if (!srcA.image || !srcB.image) return;
    a2.show(srcA.image);
    b2.show(srcB.image);
    const r = timed(p2.meta, () => dip.waveletFusion(srcA.image, srcB.image, levels.value));
    fused.show(r.fused);
    bands.show(r.subbands, `${levels.value} level(s)`);
  });
  const srcA = sourcePicker('Image A', ['mri1', 'mri2'], update2);
  const srcB = sourcePicker('Image B', ['mri2', 'mri1'], update2);
  const levels = slider('Levels', { min: 1, max: 5, value: 1 }, update2);
  p2.add(srcA, srcB, levels);

  const p3 = panel(section, 'SLIC superpixels', 'Clustering on L*a*b* color and pixel position; boundaries drawn in white.');
  const [orig3, sp] = p3.figures(figure('Original'), figure('Superpixels'));
  const update3 = coalesce(() => {
    const im = src3.image;
    if (!im) return;
    orig3.show(im);
    const r = timed(p3.meta, () => dip.slic(im, count.value, compact.value, edges.value));
    sp.show(r, `${r.superpixels} superpixels`);
  });
  const src3 = sourcePicker('Image', ['totem', 'dog', 'balloons'], update3);
  const count = slider('Superpixels', { min: 20, max: 1000, step: 10, value: 200 }, update3);
  const compact = slider('Compactness', { min: 1, max: 40, value: 10 }, update3);
  const edges = checkbox('Show boundaries', true, update3);
  p3.add(src3, count, compact, edges);

  return Promise.all([src1.load(), srcA.load(), srcB.load(), src3.load()]);
}

// ---------------------------------------------------------------- router ---

const INIT = {
  levels: initLevels,
  enhance: initEnhance,
  spatial: initSpatial,
  frequency: initFrequency,
  color: initColor,
  geometry: initGeometry,
};
const initialized = new Set();

function show(id) {
  if (!document.getElementById(id)) id = 'levels';
  for (const s of document.querySelectorAll('.project')) s.hidden = s.id !== id;
  for (const a of document.querySelectorAll('.sidebar a')) a.classList.toggle('active', a.getAttribute('href') === `#${id}`);
  if (INIT[id] && !initialized.has(id)) {
    initialized.add(id);
    INIT[id](document.getElementById(id));
  }
  window.scrollTo({ top: 0 });
}

async function main() {
  try {
    dip = await createDipModule();
  } catch (e) {
    document.getElementById('loading').innerHTML =
      '<p class="error">Failed to load the WebAssembly module. Serve this folder over HTTP (e.g. <code>python3 -m http.server</code>) rather than opening the file directly.</p>';
    throw e;
  }
  document.getElementById('loading').remove();
  window.addEventListener('hashchange', () => show(location.hash.slice(1)));
  show(location.hash.slice(1));
}

main();
