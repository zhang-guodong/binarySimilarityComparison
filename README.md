# binarySimilarityComparison



控制流图的生成方法：
$ g++ -pg example.cpp
$ valgrind --tool=callgrind ./a.out  
$ dot -Tpng report.dot -o report.png
$ ./gprof2dot.py -f callgrind callgrind.out.5391 > report.dot
$ dot -Tpng report.dot -o report.png
