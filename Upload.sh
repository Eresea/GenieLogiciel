git init
git add .
if [ "$#" = 1 ]
then
git commit -m "$1"
else
git commit -m "$0"
fi
git push origin master
