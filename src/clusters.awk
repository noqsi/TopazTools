# Assume EXT counts are neutrons.
# Pick neutron events from tsv output of qdaq.
# Look for multiple counts per interval.
# Use "elapsed" time for the acquistion as live time (no PHA dead time).
# Intended for searching for cosmic ray air showers.

BEGIN{FS="\t"}

/START/{s=$3; if( !st ) { st = s; print "\nStart Collection", st }}

/ELAPSED/{live+=$2}

/EXT/{ sum+=$2; if ($2 > 2) print $2,s }

END{ 
	print "Last Sample", s;
	print "Total Events", sum;
	print "Live Time", live, "seconds";
	print "Rate", sum/live "+-" sqrt(sum)/live " per second\n" }
