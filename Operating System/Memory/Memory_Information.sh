clear
echo -n "\nThe Kernel Version is\t:\t"
cat /proc/sys/kernel/osrelease
echo -n "\nNo of processors\t:\t"
cat /proc/cpuinfo|grep processor|wc -l
echo
cat /proc/cpuinfo|grep "model name"|head -1
echo -n "\nMemory Information\n"
echo -n "\nTotal Memory\t:\t"
x=`cat /proc/meminfo|grep MemT|cut -c 18-24`
x=`expr $x / 1024`
echo "$x MB"
echo -n "\nFree Memory\t:\t"
y=`cat /proc/meminfo|grep MemF|cut -c 19-24`
y=`expr $y / 1024`
echo "$y MB"
