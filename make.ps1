$pythonServer = get-process python
$pythonServer.Kill()
remove-item -Recurse -Path .\out
remove-item -Recurse -Path tmp
mkdir out
mkdir out\js
mkdir tmp
copy-item .\src\html\* .\out
copy-item .\src\js\* .\out\js
emcc -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -c .\src\c\draw.c -o tmp\draw.bc 
emcc -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -c .\src\c\events.c -o tmp\events.bc
emcc -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -c .\src\c\init.c -o tmp\init.bc --preload-file assets
emcc -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -c .\src\c\input.c -o tmp\input.bc
emcc -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -c .\src\c\main.c  -o tmp\main.bc
emcc tmp/draw.bc tmp/events.bc tmp/init.bc tmp/input.bc tmp/main.bc -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file assets -o out/index.js
remove-item -Recurse -Path tmp
start-process -filepath "python" -ArgumentList "-m http.server" -WorkingDirectory .\out