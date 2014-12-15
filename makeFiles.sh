dir=$1

#dd if=/dev/urandom of=$1/foobar4 oflag=direct bs=1024 count=4
#dd if=/dev/urandom of=$1/foobar8 oflag=direct bs=1024 count=8
#dd if=/dev/urandom of=$1/foobar16 oflag=direct bs=1024 count=16
#dd if=/dev/urandom of=$1/foobar32 oflag=direct bs=1024 count=32
#dd if=/dev/urandom of=$1/foobar64 oflag=direct bs=1024 count=64
#dd if=/dev/urandom of=$1/foobar128 oflag=direct bs=1024 count=128
#dd if=/dev/urandom of=$1/foobar256 oflag=direct bs=1024 count=256
#dd if=/dev/urandom of=$1/foobar512 oflag=direct bs=1024 count=128

#dd if=/dev/urandom of=$1/foobar1M oflag=direct bs=1M count=1
#dd if=/dev/urandom of=$1/foobar2M oflag=direct bs=1M count=2
dd if=/dev/urandom of=$1/foobar4M oflag=direct bs=1M count=4
dd if=/dev/urandom of=$1/foobar8M oflag=direct bs=1M count=8
dd if=/dev/urandom of=$1/foobar16M oflag=direct bs=1M count=16
dd if=/dev/urandom of=$1/foobar32M oflag=direct bs=1M count=32
dd if=/dev/urandom of=$1/foobar64M oflag=direct bs=1M count=64
dd if=/dev/urandom of=$1/foobar128M oflag=direct bs=1M count=128
dd if=/dev/urandom of=$1/foobar256M oflag=direct bs=1M count=256
dd if=/dev/urandom of=$1/foobar512M oflag=direct bs=1M count=512
dd if=/dev/urandom of=$1/foobar1024M oflag=direct bs=1M count=1024
dd if=/dev/urandom of=$1/foobar2048M oflag=direct bs=1M count=2048

dd if=/dev/urandom of=$1/foobar1100M oflag=direct bs=1M count=1100
dd if=/dev/urandom of=$1/foobar1200M oflag=direct bs=1M count=1200
dd if=/dev/urandom of=$1/foobar1300M oflag=direct bs=1M count=1300
dd if=/dev/urandom of=$1/foobar1400M oflag=direct bs=1M count=1400
dd if=/dev/urandom of=$1/foobar1500M oflag=direct bs=1M count=1500

