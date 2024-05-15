prog: dep_joueur.o background.o enigme.o tik.o tic.o enemie.o minimap.o
	gcc dep_joueur.o background.o enigme.o tik.o tic.o enemie.o minimap.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx -g

dep_joueur.o: dep_joueur.c
	gcc -c dep_joueur.c -o dep_joueur.o -g

background.o: background.c background.h
	gcc -c background.c -o background.o -g

enigme.o: enigme.c enigme.h
	gcc -c enigme.c -o enigme.o -g

ennemie.o: enemie.c enemie.h
	gcc -c enemie.c -o enemie.o -g

tik.o: tik.c tik.h
	gcc -c tik.c -o tik.o -g

tic.o: tic.c tic.h
	gcc -c tic.c -o tic.o -g


minimap.o: minimap.c minimap.h
	gcc -c minimap.c -o minimap.o -g
	
clean:
	rm -f dep_joueur.o background.o enigme.o tik.o tic.o enemie.o minimap.o prog

