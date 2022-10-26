cd files
for fp in *.txt; do mv $fp $(date +%y-%m-%d)_$fp; done
for fp in *.csv; do mv $fp $(date +%y-%m-%d)_$fp; done
for fp in *.pdf; do mv $fp $(date +%y-%m-%d)_$fp; done
for fp in *.api; do mv $fp $(date +%y-%m-%d)_$fp; done
for fp in *.plist; do mv $fp $(date +%y-%m-%d)_$fp; done
