all: especifico
	echo "hecho"

generador:
	cd ./Generador && $(MAKE)
	mv ./Generador/generador .

especifico:
	cd ./Especifico && $(MAKE)
	mv ./Especifico/especifico .

dyv:
	cd ./Dyv && $(MAKE)
	mv ./Dyv/dyv .
