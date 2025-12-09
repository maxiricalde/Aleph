# Usamos una imagen base ligera de Debian que tenga GCC
FROM debian:bullseye-slim

# Actualizamos e instalamos las herramientas necesarias
# build-essential incluye gcc, make, etc.
RUN apt-get update && apt-get install -y \
    flex \
    bison \
    build-essential \
    gdb \
    git \
    valgrind \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Establecemos el directorio de trabajo dentro del contenedor
WORKDIR /usr/src/app

# Por defecto, al entrar, abrimos una bash
CMD ["/bin/bash"]
