BEGIN{FS="\t"}

/START/{s=$3}

/EXT/{if ($2 > 0) print $2,s}
