# Base image to build our image on
FROM alpine:latest AS build

# Copy src folder from dockerfile directory to container's /app/src 
COPY src /app/src
# The same sa copy, but works with url's and can decompress .tar files
# ADD https://URL.com

# Change the working directory to /app
WORKDIR /app

# Run the command to install the dependancies on build time
RUN apk update; apk add python3 py3-pip

# Cria uma variável de ambiente na imagem,
# Tbm é possível utilizar no próprio Dockerfile
# ENV MAIN=main.py

# Expose the 8080 port
#EXPOSE 8080

# Run "python3 main.py" during start 
CMD["python3", "main.py"]

# Mesmo que CMD, mas quando este está presente, o CMD serve de parâmetro pro entrypoint
# ENTRYPOINT["python3"]
