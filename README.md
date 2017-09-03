# json-disk
A simple C application to get the information about mountpoints and free space with JSON output.

# Example output
```json
[
  {
    "mountpoint": "/",
    "free": 1092571136,
    "total": 20506800128,
    "type": "ext4",
    "fsname": "/dev/md2",
    "fsopts": "errors=remount-ro,relatime"
  },
  {
    "mountpoint": "/srv",
    "free": 304944160768,
    "total": 3916700098560,
    "type": "ext4",
    "fsname": "/dev/md3",
    "fsopts": "defaults,relatime"
  },
  {
    "mountpoint": "swap",
    "free": 304944160768,
    "total": 3916700098560,
    "type": "swap",
    "fsname": "/dev/sda4",
    "fsopts": "defaults"
  },
  {
    "mountpoint": "swap",
    "free": 304944160768,
    "total": 3916700098560,
    "type": "swap",
    "fsname": "/dev/sdb4",
    "fsopts": "defaults"
  },
  {
    "mountpoint": "swap",
    "free": 304944160768,
    "total": 3916700098560,
    "type": "swap",
    "fsname": "/dev/sdc4",
    "fsopts": "defaults"
  },
  {
    "mountpoint": "/dev/shm",
    "free": 8401739776,
    "total": 8401739776,
    "type": "tmpfs",
    "fsname": "tmpfs",
    "fsopts": "defaults"
  }
]
```