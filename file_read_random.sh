RUNS=200

echo -n 4,; ./file_read_random.out $1/foobar4M $RUNS | python ./avg.py
echo -n 8,; ./file_read_random.out $1/foobar8M $RUNS | python ./avg.py
echo -n 16,; ./file_read_random.out $1/foobar16M $RUNS | python ./avg.py
echo -n 32,; ./file_read_random.out $1/foobar32M $RUNS | python ./avg.py
echo -n 64,; ./file_read_random.out $1/foobar64M $RUNS | python ./avg.py
echo -n 128,; ./file_read_random.out $1/foobar128M $RUNS | python ./avg.py
echo -n 256,; ./file_read_random.out $1/foobar256M $RUNS | python ./avg.py
echo -n 512,; ./file_read_random.out $1/foobar512M $RUNS | python ./avg.py
#echo -n 1024,; ./file_read_seq.out /tmp/foobar1024M $RUNS | python ./avg.py
#echo -n 2048,; ./file_read_seq.out /tmp/foobar2048M $RUNS | python ./avg.py

