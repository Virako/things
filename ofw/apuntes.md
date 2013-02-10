Formas de gobernar:
===================
Democracia - votos semanales.
Anarquía - hablar
Dictadura - golpe estado
Más sabio - más tiempo jugando
República??


Personajes:
===========
Mago-diseñador --> manos y cabeza de pulpo, ojos de camaleón y pelo largo. xD


Terreno:
========
Disco duro cilíndrico de 10 km de diámetro y 2 km de alto.
La velocidad de los personajes oscilará entre 5 km andando y 10 km corriendo.
La velocidad de las monturas oscilará entre 10 km normal y 20 km rápido.
Como los personajes van a ser de un metro podría todo rebajarlo a la mitad


Skill: (skill primarias, secundarias y específicas)
===================================================
Construcción (puentes, edificios, )
Conocimiento (personajes, bichos y objetos, aldeas, ...)
nadar?
robar
cazar
talar
trampas (huecos en el suelo, pasadizos secretos)
recolector (diferentes cosas. bichos muertos por ejemplo)


Trabajos:
=========
forjador de armas
sastre
constructor
cazador
pescador
cocinero
domador



Opciones del juego:
===================
no dinero
apostar objetos en una batalla o cosas de ese estilo
mas puntos si mas beneficio a la sociedad y viceversa
entretenimiento que sea la mayor parte del tiempo. Cosas para hacer:
    coleccionar fotos de bichos
    comer (fruta, animales y rocas. transistores, diodos, etc)
    bebida (x10 para toda la gente)
investigar el mapa
reproducción
capturar bichos para investigar
tener una casa
transporte (montura)
mochila
no mostrar los niveles
los bichos comen y se reproducen
comida venenosa
la gente que se mate entre ella recibirá algo de beneficio, para que así conseguir algo
npc del juego que hagan cosas que hacen los jugadores normales, como recolectar, cazar, etc
libreta para apuntes
SERVER EXCLUSIVO DONDE SI MUERES PIERDES
Crear una aplicación android para ver el estado del juego.
Avisar en linuxjuegos y sitios como ese de que existe nuestro juego.


Programación del videojuego:
============================
# DEJAR solo los width and height en character con las pruebas y mirar que el personaje funcione con esos valores.
cargar personaje en la pantalla.
    * load mesh
    * rotate, scale and position
    * camera
    * animaciones. diferencias entre md2, md3 y b3d
Visualizador de Materiales, efectos texturas e iluminación con Irrlicht
    material (mapas): diffuse, ambient, specular, filter, glosiness, bump, ...
Cargar personaje en la pantalla utilizando la clase personaje (boost)
Cargar mapa en pantalla
Cargar mapa en la pantalla utilizando la clase mapa (boost)
Dar movimiento al personaje
Estructurar ese movimiento del personaje dando unas configuraciones de teclas
Estructurar mejor las configuraciones, añadir configuración de video en ese apartado
Añadir colisiones
Vista del personaje con la cámara
Añadir la base de datos para obtener el id de las cosas y guardar todo
Añadir un bicho y un npc. IA. clases npc y bug que heren de character, y player añadirlo también
Conectar con el servidor para llevar el juego y comprobar chetos e inicios de sesion
======================== ILUMINACION Y CÁMARA
Chat [IGUAL MAS ADELANTE]



Formato de las clases:
======================
character --> color, id(bd), name, skill[], item[](mochila), item[](equipacion), pos, modelo, textura, animaciones[], velocidad, lvl, life. IMPORTANTE: cambiar textura del personaje dependiendo de la distancia a la que se encuentre, para mejorar la carga.
    player --> clase, user, pass, email, MAC?
        password, buscar un sistema de seguridad
        Namespace para los 5 tipos de personajes. ENUM: PICAC=1, HACKE, ..., =5
    npc --> IA
    bug --> IA, clase
        Probabilidad de que aparezca un bicho.
        Sitios donde aparece.
        Como matarlo. Dependerá de las skill?
manejador de personaje: teclas wasd para mover y las de direcciones también.
    raton: izq y der para rotar personaje.
    raton: arriba/abajo para ver más arriba o más abajo.
    rueda: alejar/acercar vista personaje (poner limites)
map --> dividir mapa
item(mochila) -->
skill -->
config --> keys, video
main -->
gui --> inicio sesion, configuracion de audio, video
audio -->
misiones -->
aldeas -->



Post:
=====
Como colaborar. guía de estilo. tests.
Como comenzar un proyecto de SL. Herramientas, bibliotecas, organización, estructuración,
Creacion de entorno y modelo. Añadir texturas, luces, materiales, etc

******
5 o 6 apartados específicos: C++, CMake, Boost, Irrlicht, mongodb
# Nuevo colaborador para los gráficos
Exportacion de archivos
Luces, texturas, materiales, etc
BD con MongoDB
******

OTROS:
======
CPack (.deb, .exe, .rpm, etc)??

