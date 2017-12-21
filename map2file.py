#!/usr/bin/python3

import sys
#converts 16x16 map to tuwk map file
#usage: map2file.py map_name < map.txt
'''
map template filled with floor,
w - wall, p - player, s - storage spot, b - box, f - floor
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
ffffffffffffffff
'''
if len(sys.argv) > 1 and len(sys.argv[1]) <= 32:
	map_buffer = ""
	storages_count = 0
	for line in sys.stdin.read().split():
		map_buffer += line
		for c in line:
			if c == 's':
				storages_count += 1
	map_buffer = str(storages_count) + map_buffer
	if len(map_buffer) == 257 and 0 < storages_count < 10 :
		mapfile = open(sys.argv[1],'w')
		mapfile.write(map_buffer)
	else:
		print("Wrong map resolution or number of storage spots")
else:
	print("Map name not provided or too long");



