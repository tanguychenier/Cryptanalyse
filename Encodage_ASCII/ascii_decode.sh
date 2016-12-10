#!/bin/sh

read -p 'Entrez votre clé: ' cle
echo  "$cle" | xxd -p -r
