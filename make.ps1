$pythonServer = get-process python
$pythonServer.Kill()
remove-item -Recurse -Path .\out
mkdir out
mkdir out\js
cp .\src\html\* .\out
cp .\src\js\* .\out\js
emcc .\src\c\main.c -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file assets -o out/index.js

start-process -filepath "python" -ArgumentList "-m http.server" -WorkingDirectory .\out