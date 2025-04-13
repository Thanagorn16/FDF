# 🌄 FDF — 3D Wireframe Renderer
>A minimalist C program that transforms 3D elevation data into a 2D wireframe using isometric projection.

---

### 📌 Project Description
FDF (Fil de Fer, French for wireframe) is a graphical program that reads elevation maps and visualizes them in a 2D isometric projection. This project was developed as part of the 42 School curriculum, with the goal of mastering fundamental graphics, coordinate transformation, and low-level system programming in C.

---

### ✨ Features
🔹 Parse 3D elevation data from .fdf map files

🔹 Render wireframe models using isometric projection

🔹 Support interactive controls (zoom, pan, rotate, adjust elevation)

🔹 Display smooth lines using Bresenham’s algorithm

🔹 Real-time redrawing and responsive UI

---

### ⚙️ Technologies Used
🧠 C Language — Core language used for performance and control

🎨 MiniLibX — Lightweight graphical library for window management and drawing

📐 Bresenham's Line Algorithm — For accurate and efficient line rendering

🔲 Matrix math — To handle 3D to 2D coordinate projection

---

### 🚧 Challenges Faced
Implementing accurate isometric transformations manually

Drawing pixel-perfect lines and preventing graphic tearing

Ensuring responsive user controls and redraw efficiency

Handling variable map sizes and memory allocation dynamically

---

### 📁 Table of Contents

- [📌 Project Description](#-project-description)  
- [✨ Features](#-features)  
- [⚙️ Technologies Used](#-technologies-used)  
- [🚧 Challenges Faced](#-challenges-faced)  
- [🔧 Installation](#-installation)  
- [🚀 Usage](#-usage)  
- [🎮 Controls](#-controls)  
- [📸 Examples](#-examples)  

--- 

### 🔧 Installation
#### 📦 Requirements
- Unix-like system (Linux/macOS)

- ```gcc``` compiler

- ```make``` utility

- __MiniLibX__ library (comes with 42 environment or install manually)

### 🚀 Setup
```bash
git clone https://github.com/Thanagorn16/FDF.git
cd FDF
make
```
This will generate an executable called fdf.

---

### 🚀 Usage
```bash
./fdf <map_file.fdf>
```

### 🧪 Example
```bash
./fdf maps/42.fdf
```

--- 

### 🎮 Controls

| Key              | Action                            |
|------------------|------------------------------------|
| ⬅️ ➡️ ⬆️ ⬇️       | Pan the map                        |
| `+` / `-`         | Zoom in / out                     |
| `W` / `S`         | Increase / decrease height scale  |
| `A` / `D`         | Rotate left / right               |
| `ESC`            | Exit the program                  |

