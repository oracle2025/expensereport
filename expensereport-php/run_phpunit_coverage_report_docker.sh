#!/bin/bash -xe
docker-compose run test-runner ./vendor/bin/phpunit --coverage-html pHTML
