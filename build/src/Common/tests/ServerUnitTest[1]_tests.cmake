add_test( ServerUnitTest.testDemo /home/typhigh/Desktop/OpenSource/TColDB/build/src/Common/tests/ServerUnitTest [==[--gtest_filter=ServerUnitTest.testDemo]==] --gtest_also_run_disabled_tests)
set_tests_properties( ServerUnitTest.testDemo PROPERTIES WORKING_DIRECTORY /home/typhigh/Desktop/OpenSource/TColDB/build/src/Common/tests)
set( ServerUnitTest_TESTS ServerUnitTest.testDemo)
