# Assume EXT counts are neutrons.
# Pick neutron events from tsv output of qdaq.
# Print times of their acq cycles, total number, and rate.
# Use "elapsed" time for the acquistion as live time (no PHA dead time).
# Intended for background monitoring (low rate).

BEGIN{FS="\t"}

/START/{s=$3}

/ELAPSED/{live+=$2}

/EXT/{ sum+=$2; if ($2 > 0) print $2,s }

END{ 
	print "Total Events", sum;
	print "Live Time", live, "seconds";
	print "Rate", sum/live "+-" sqrt(sum)/live " per second" }
