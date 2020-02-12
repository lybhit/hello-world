#!/usr/bin/env python

locations = dict()

locations['B1'] = "1"
locations['B2'] = "2"
locations['B3'] = "3"
locations['B5'] = "4"
locations['B4'] = "5"
locations['B0'] = "6"

keys = locations.keys()
keys.sort()

print keys[1]

for i in keys:
    print i

for k in sorted(locations.keys()):
    print locations[k]
#for i in locations.keys():
#    print locations[i]

print locations

