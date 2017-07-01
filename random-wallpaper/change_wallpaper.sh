# download the image from unsplash.com using cURL
curl -L https://source.unsplash.com/random/1920x1080 > random_wallpaper.jpg

# set it as wallpaper (works on gnome and unity)
gsettings set org.gnome.desktop.background picture-uri file://$PWD/random_wallpaper.jpg
