dir=$1

dd if=/dev/urandom of=$1/foobar4M oflag=direct bs=1M count=4
dd if=/dev/urandom of=$1/foobar8M oflag=direct bs=1M count=8
dd if=/dev/urandom of=$1/foobar16M oflag=direct bs=1M count=16
dd if=/dev/urandom of=$1/foobar32M oflag=direct bs=1M count=32
dd if=/dev/urandom of=$1/foobar64M oflag=direct bs=1M count=64
dd if=/dev/urandom of=$1/foobar128M oflag=direct bs=1M count=128
dd if=/dev/urandom of=$1/foobar256M oflag=direct bs=1M count=256
dd if=/dev/urandom of=$1/foobar512M oflag=direct bs=1M count=512

dd if=/dev/urandom of=$1/foobar700M oflag=direct bs=1M count=700
dd if=/dev/urandom of=$1/foobar800M oflag=direct bs=1M count=800
dd if=/dev/urandom of=$1/foobar850M oflag=direct bs=1M count=850
dd if=/dev/urandom of=$1/foobar900M oflag=direct bs=1M count=900
dd if=/dev/urandom of=$1/foobar950M oflag=direct bs=1M count=950

dd if=/dev/urandom of=$1/foobar1024M oflag=direct bs=1M count=1024

dd if=/dev/urandom of=$1/foobar1100M oflag=direct bs=1M count=1100
dd if=/dev/urandom of=$1/foobar1200M oflag=direct bs=1M count=1200
dd if=/dev/urandom of=$1/foobar1300M oflag=direct bs=1M count=1300
dd if=/dev/urandom of=$1/foobar1400M oflag=direct bs=1M count=1400
dd if=/dev/urandom of=$1/foobar1500M oflag=direct bs=1M count=1500

dd if=/dev/urandom of=$1/foobar2048M oflag=direct bs=1M count=2048
