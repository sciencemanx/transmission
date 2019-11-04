#! /bin/bash

set -e

image=beta.internal.forallsecure.com:5000/transmission

docker build -t $image . -f docker/fuzz/Dockerfile
docker push $image
docker run -ti $image
