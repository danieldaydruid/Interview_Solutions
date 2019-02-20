LIDAR Filters (Range, Temporal Median) README Document

This software limits incoming noise in scans from LIDAR sensors attached to remote robots.

Currently this software filters Range scans for minimum and maximum permissible values and tracks Temporal Median values of current and D previous scans.

All attached code was written in C++ and compiled using g++ v. 7.3.0.

To build and execute, download all included files and utilize the included makefile in the appropriate directory from the terminal like so: make && ./LidarFilter

Tests include the provided base case from the prompt, a NULL case, in which the array provided to the filter objects are NULL, a test which uses
the maximum and minimum allowable float values (+/-1e38) as the elements in the scans, a test which randomly assigns scan size and element count
between 0 and 1000 and randomly assigns D between 3 and 50, and filters all of these scans accordingly. The final dispplayed test contains 20 scans
of 20 elements each with a D randomly assigned between 3 and 20. This final test is a way to display the accuracy of the filters in a readable format.
There is also an ExampleOutput.txt document attached in order to easily view results from the filters on an average run of the above tests.

All test cases will run automatically upon program execution.