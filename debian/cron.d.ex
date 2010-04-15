#
# Regular cron jobs for the pyoa package
#
0 4	* * *	root	[ -x /usr/bin/pyoa_maintenance ] && /usr/bin/pyoa_maintenance
