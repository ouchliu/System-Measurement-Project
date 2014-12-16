RUNS=30

echo -n 4,; ./file_cache.out /tmp/foobar4M $RUNS | python ./avg.py
echo -n 8,; ./file_cache.out /tmp/foobar8M $RUNS | python ./avg.py
echo -n 16,; ./file_cache.out /tmp/foobar16M $RUNS | python ./avg.py
echo -n 32,; ./file_cache.out /tmp/foobar32M $RUNS | python ./avg.py
echo -n 64,; ./file_cache.out /tmp/foobar64M $RUNS | python ./avg.py
echo -n 128,; ./file_cache.out /tmp/foobar128M $RUNS | python ./avg.py
echo -n 256,; ./file_cache.out /tmp/foobar256M $RUNS | python ./avg.py
echo -n 512,; ./file_cache.out /tmp/foobar512M $RUNS | python ./avg.py

echo -n 700,; ./file_cache.out /tmp/foobar700M $RUNS | python ./avg.py
echo -n 800,; ./file_cache.out /tmp/foobar800M $RUNS | python ./avg.py
echo -n 850,; ./file_cache.out /tmp/foobar850M $RUNS | python ./avg.py
echo -n 900,; ./file_cache.out /tmp/foobar900M $RUNS | python ./avg.py
echo -n 950,; ./file_cache.out /tmp/foobar950M $RUNS | python ./avg.py

echo -n 1024,; ./file_cache.out /tmp/foobar1024M $RUNS | python ./avg.py

echo -n 1100,; ./file_cache.out /tmp/foobar1100M $RUNS | python ./avg.py
echo -n 1200,; ./file_cache.out /tmp/foobar1200M $RUNS | python ./avg.py
echo -n 1300,; ./file_cache.out /tmp/foobar1300M $RUNS | python ./avg.py
echo -n 1400,; ./file_cache.out /tmp/foobar1400M $RUNS | python ./avg.py
echo -n 1500,; ./file_cache.out /tmp/foobar1500M $RUNS | python ./avg.py

echo -n 2048,; ./file_cache.out /tmp/foobar2048M $RUNS | python ./avg.py

