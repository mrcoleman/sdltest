$CC=emcc
$STDLIBS= -s WASM=1 \
	-s USE_SDL=2 \
	-s USE_SDL_IMAGE=2 \
sdl-wasm:
	$CC main.c \
	$STDLIBS \
	-s SDL2_IMAGE_FORMATS='["png"]' \
	--preload-file assets \
	-o index.js