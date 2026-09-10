"""
Julia Set Fractal Generator
----------------------------
Renders a high-resolution Julia set using vectorized NumPy computation
and smooth (continuous) iteration coloring for a rich, gradient look.

Fractal type   : Julia Set  (z_{n+1} = z_n^2 + c)
Libraries used : NumPy, Matplotlib

Author: <YOUR NAME HERE>
Reg No: <YOUR REGISTRATION NUMBER HERE>
"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LinearSegmentedColormap


# ----------------------------------------------------------------------
# 1. Fractal parameters
# ----------------------------------------------------------------------
WIDTH, HEIGHT = 1600, 1600      # output resolution (pixels)
MAX_ITER = 300                  # higher -> more detail, slower render
ESCAPE_RADIUS = 4.0              # standard bailout radius for z^2 + c

# 'c' controls the shape of the Julia set.
# This value produces a well-known, visually striking swirling pattern.
C = complex(-0.7, 0.27015)

# Viewing window in the complex plane
X_MIN, X_MAX = -1.5, 1.5
Y_MIN, Y_MAX = -1.5, 1.5


# ----------------------------------------------------------------------
# 2. Compute the Julia set with smooth (continuous) coloring
# ----------------------------------------------------------------------
def compute_julia(width, height, c, max_iter, escape_radius):
    x = np.linspace(X_MIN, X_MAX, width)
    y = np.linspace(Y_MIN, Y_MAX, height)
    X, Y = np.meshgrid(x, y)
    Z = X + 1j * Y

    # Smooth iteration count (fractional escape time) for gradient shading
    smooth_iter = np.zeros(Z.shape, dtype=float)
    mask = np.ones(Z.shape, dtype=bool)   # pixels that have not escaped yet

    for i in range(max_iter):
        Z[mask] = Z[mask] ** 2 + c
        escaped = np.abs(Z) > escape_radius

        newly_escaped = escaped & mask
        # Smooth coloring formula: i + 1 - log(log|Z|) / log(2)
        with np.errstate(invalid="ignore", divide="ignore"):
            smooth_iter[newly_escaped] = (
                i + 1 - np.log(np.log(np.abs(Z[newly_escaped]))) / np.log(2)
            )

        mask &= ~escaped
        if not mask.any():
            break

    # Points still inside the set at max_iter keep value max_iter (deep color)
    smooth_iter[mask] = max_iter
    return smooth_iter


# ----------------------------------------------------------------------
# 3. Custom color palette (deep indigo -> magenta -> coral -> gold)
# ----------------------------------------------------------------------
def build_colormap():
    colors = [
        (0.00, "#000814"),  # near-black navy (deep set interior)
        (0.15, "#03045e"),  # dark indigo
        (0.35, "#7209b7"),  # violet
        (0.55, "#d00070"),  # magenta/pink
        (0.75, "#ff6d00"),  # coral orange
        (0.90, "#ffd60a"),  # gold
        (1.00, "#fffbe6"),  # warm near-white highlight
    ]
    positions = [p for p, _ in colors]
    hex_colors = [c for _, c in colors]
    return LinearSegmentedColormap.from_list("julia_sunset", list(zip(positions, hex_colors)))


# ----------------------------------------------------------------------
# 4. Render and save
# ----------------------------------------------------------------------
def main():
    print("Computing Julia set...")
    data = compute_julia(WIDTH, HEIGHT, C, MAX_ITER, ESCAPE_RADIUS)

    # Normalize for smoother color transitions
    data = np.sqrt(np.clip(data, 0, MAX_ITER) / MAX_ITER)

    cmap = build_colormap()

    fig, ax = plt.subplots(figsize=(10, 10), dpi=160)
    ax.imshow(data, cmap=cmap, extent=(X_MIN, X_MAX, Y_MIN, Y_MAX), origin="lower")
    ax.set_axis_off()
    fig.patch.set_facecolor("#000814")
    plt.tight_layout(pad=0)

    output_path = "julia_set.png"
    plt.savefig(output_path, dpi=160, bbox_inches="tight", pad_inches=0, facecolor="#000814")
    print(f"Saved fractal image to {output_path}")
    plt.show()


if __name__ == "__main__":
    main()
