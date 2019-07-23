# Frayja

![CPP](https://img.shields.io/badge/C++-11-blue.svg)
[![License](https://img.shields.io/badge/license-LGPL-blue.svg)](https://opensource.org/licenses/MIT)

C++ Raytracing software with Qt GUI.
The raytracer engine of the software is based on the raytracing books of Peter Shirley (http://www.realtimerendering.com/raytracing/)

## Features

- Gui (customization of rendering configuration and camera configuration)
- XML scene files
- Multithreading
- "Real-time" view of the rendering.
- Dockable menu toolbar and Configuration menu
- Save rendered image in ppm format
- Materials
- Shapes (only circle for the moment)
- Motion blur
- BVH acceleration sctructure
- Perlin noise
- Checker pattern

## Screenshots

GUI
![Alt text](/Res/FrayjaUI.PNG?raw=true "Optional Title")

GUI during rendering
![Alt text](/Res/FrayjaRendering.PNG?raw=true "Optional Title")

Scene 3
![Alt text](/Output/scene3.png?raw=true "Optional Title")

Scene 6
![Alt text](/Output/scene6.png?raw=true "Optional Title")

## Getting Started

### Prerequisites

Windows only.

Visual studio and Qt installed.

### How to use it

Launch the executable either inside Visual Studio or standalone.

You may need to resize the window at the beggining! If you use a 4k display, uncomment the first line of main.cpp file.

## License

This project is licensed under the GNU Lesser General Public License v3.0 - see the [LICENSE.md](LICENSE.md) file for details
