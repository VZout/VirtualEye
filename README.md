[![Shippable](https://img.shields.io/shippable/5444c5ecb904a4b21567b0ff.svg?maxAge=2592000)]()
[![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/bjornus/VirtualEye/blob/master/LICENSE)

<img src="logo.png">

# VirtualEye - 2D Render Game
VirtualEye is Render Game Engine make for fun and gain experiance. A keynote to create this library is simplicity to create small games and simple RPG, shooters etc. In future i want to add python script creating, and move onUpdate() and onInit() function into them.

## License
VirtualEye is under MIT license. It means, you can create your own game on it, sell it, authorize it, but you MUST write that VirtualEye is Dmitro Szewczuk own.

## Features
[x] Map loading
[x] Sprite loading
[x] Easy to use
[x] Independent map formats
[ ] UI

## How to build(Linux)
1. Install gcc compiler
2. Install SDL2 and SDL2_image.
3. Install cmake
4. Install git
5. Clone repo by:

  $ git clone https://github.com/bjornus/VirtualEye.git

6. Make it

  $ cd VirtualEye

  $ cmake .
  
  $ make

7. Run it!

  $ cd tests/Pong

  $ ./VirtualEye
