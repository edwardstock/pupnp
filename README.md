## Updates for "classical" libupnp

[Original README here](README)

This repository is a fork of the 
[Portable SDK for UPnP Devices](http://pupnp.sourceforge.net/) project, 
which itself forked the original Intel project in 2006, motivated
by the stagnation of the original project.

It seems that history repeats itself, because the current Sourceforge
project linked above does not receive many updates.

This repository will continue tracking branch 1.6 of the Sourceforge
project, but will also be updated with bug fixes which appear to have
trouble getting into the Sourceforge repository. 

The compatibility with the original API will be strictly preserved.

This README will keep a synthetic description of the local updates, see
list below, newest first.


### Prevent non-responding control point from using up all device threads

February 2015

When a device is connected to multiple subscribed control points (for
example a Media Renderer connected to multiple OpenHome Control Points, or
to a classical UPnP AV Control Point and to one displaying the current
title), events are dispatched to all CPs to update information about the
device state.

Prior to this modification, a subscribed control point which became
unreachable without unsubscribing would cause all device threads to become
stuck in HTTP connect calls with a long timeout (30 S). Seen from the other
Control Points, the device would appear to respond very sporadically or not
at all.

The modifications changes the way outgoing events are processed: instead of
dumping them into the thread pool and hoping for the best, they are queued
on the subscription structure, and only activated when the previous event
for the same subscription has been processed. This ensure that at most one
thread can be working for a given subscription. In addition, the
per-subscription queue is limited in size and events are discarded when the
size is exceeded.

Also, the timeout for the connect() call is controlled and shorter by
default, instead of being left up to the system default.



