#include "Array.hpp"
#include <exception>
#include <iostream>
#include <limits>

int test_ocf(void) {
  int res = 0;
  int err = 0;
  // Default Constructor
  std::cout << "\n====Default Constructor Test====" << std::endl;
  Array<int> arr = Array<int>();
  if (arr.size() == 0)
    std::cout << "Array is empty as expected" << std::endl;
  else {
    std::cout << "Array is not empty" << std::endl;
    res = 1;
  }
  std::cout << "Array size: " << arr.size() << std::endl;
  // Copy COnstructor
  std::cout << "\n====Copy Constructor Test====" << std::endl;
  Array<int> arr1 = Array<int>(3);
  for (size_t i = 0; i < arr1.size(); i++) {
    arr1[i] = static_cast<int>(i);
  }
  Array<int> arr2(arr1);
  for (size_t i = 0; i < arr1.size(); i++) {
    if (arr1[i] == arr2[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Constructor Succeeded." << std::endl;
  err = 0;
  std::cout << "\n====Copy Assignment Operator Test====" << std::endl;
  for (size_t i = 0; i < arr2.size(); i++) {
    arr2[i] = static_cast<int>(i + 3);
  }
  Array<int> arr3 = Array<int>(arr2.size());
  arr3 = arr2;
  for (size_t i = 0; i < arr2.size(); i++) {
    if (arr2[i] == arr3[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Assignment Succeeded." << std::endl;
  std::cout << "\n====Empty Array Access====\n" << std::endl;
  int exception_occurred = 0;
  try {
    arr[0];
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception Did not occurr." << std::endl;
    err = 1;
    res = 1;
  }
  err = 0;
  return (res);
}

int subscript_test(void) {
  int res = 0;
  int exception_occurred = 0;
  std::cout << "\n====Subscript Access====" << std::endl;
  Array<int> arr1 = Array<int>(3);
  std::cout << std::endl;
  for (size_t i = 0; i < arr1.size(); i++) {
    std::cout << "arr[" << i << "]: " << arr1[i] << std::endl;
  }
  size_t out_idx = arr1.size();
  try {
    std::cout << arr1[out_idx] << std::endl;
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << "\nexpected: std::exception\n";
    std::cout << "actual:" << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception not thrown when index is out of bounds"
              << std::endl;
    res = 1;
  }
  return (res);
}

int test_ocf_float(void) {
  int res = 0;
  int err = 0;
  std::cout << "\n====Float: Default Constructor Test====" << std::endl;
  Array<float> arr = Array<float>();
  if (arr.size() == 0)
    std::cout << "Array is empty as expected" << std::endl;
  else {
    std::cout << "Array is not empty" << std::endl;
    res = 1;
  }
  std::cout << "Array size: " << arr.size() << std::endl;
  std::cout << "\n====Float: Copy Constructor Test====" << std::endl;
  Array<float> arr1 = Array<float>(3);
  for (size_t i = 0; i < arr1.size(); i++) {
    arr1[i] = static_cast<float>(i) + 0.5f;
  }
  Array<float> arr2(arr1);
  for (size_t i = 0; i < arr1.size(); i++) {
    if (arr1[i] == arr2[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Constructor Succeeded." << std::endl;
  err = 0;
  std::cout << "\n====Float: Copy Assignment Operator Test====" << std::endl;
  for (size_t i = 0; i < arr2.size(); i++) {
    arr2[i] = static_cast<float>(i) + 1.5f;
  }
  Array<float> arr3 = Array<float>(arr2.size());
  arr3 = arr2;
  for (size_t i = 0; i < arr2.size(); i++) {
    if (arr2[i] == arr3[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Assignment Succeeded." << std::endl;
  std::cout << "\n====Float: Empty Array Access====" << std::endl;
  int exception_occurred = 0;
  try {
    arr[0];
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception Did not occurr." << std::endl;
    err = 1;
    res = 1;
  }
  return (res);
}

int subscript_test_float(void) {
  int res = 0;
  int exception_occurred = 0;
  std::cout << "\n====Float: Subscript Access====" << std::endl;
  Array<float> arr1 = Array<float>(3);
  std::cout << std::endl;
  for (size_t i = 0; i < arr1.size(); i++) {
    std::cout << "arr[" << i << "]: " << arr1[i] << std::endl;
  }
  size_t out_idx = arr1.size();
  try {
    std::cout << arr1[out_idx] << std::endl;
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << "\nexpected: std::exception\n";
    std::cout << "actual:" << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception not thrown when index is out of bounds"
              << std::endl;
    res = 1;
  }
  return (res);
}

int test_ocf_double(void) {
  int res = 0;
  int err = 0;
  std::cout << "\n====Double: Default Constructor Test====" << std::endl;
  Array<double> arr = Array<double>();
  if (arr.size() == 0)
    std::cout << "Array is empty as expected" << std::endl;
  else {
    std::cout << "Array is not empty" << std::endl;
    res = 1;
  }
  std::cout << "Array size: " << arr.size() << std::endl;
  std::cout << "\n====Double: Copy Constructor Test====" << std::endl;
  Array<double> arr1 = Array<double>(3);
  for (size_t i = 0; i < arr1.size(); i++) {
    arr1[i] = static_cast<double>(i) + 0.25;
  }
  Array<double> arr2(arr1);
  for (size_t i = 0; i < arr1.size(); i++) {
    if (arr1[i] == arr2[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Constructor Succeeded." << std::endl;
  err = 0;
  std::cout << "\n====Double: Copy Assignment Operator Test====" << std::endl;
  for (size_t i = 0; i < arr2.size(); i++) {
    arr2[i] = static_cast<double>(i) + 1.75;
  }
  Array<double> arr3 = Array<double>(arr2.size());
  arr3 = arr2;
  for (size_t i = 0; i < arr2.size(); i++) {
    if (arr2[i] == arr3[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Assignment Succeeded." << std::endl;
  std::cout << "\n====Double: Empty Array Access====" << std::endl;
  int exception_occurred = 0;
  try {
    arr[0];
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception Did not occurr." << std::endl;
    err = 1;
    res = 1;
  }
  return (res);
}

int subscript_test_double(void) {
  int res = 0;
  int exception_occurred = 0;
  std::cout << "\n====Double: Subscript Access====" << std::endl;
  Array<double> arr1 = Array<double>(3);
  std::cout << std::endl;
  for (size_t i = 0; i < arr1.size(); i++) {
    std::cout << "arr[" << i << "]: " << arr1[i] << std::endl;
  }
  size_t out_idx = arr1.size();
  try {
    std::cout << arr1[out_idx] << std::endl;
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << "\nexpected: std::exception\n";
    std::cout << "actual:" << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception not thrown when index is out of bounds"
              << std::endl;
    res = 1;
  }
  return (res);
}

int test_ocf_string(void) {
  int res = 0;
  int err = 0;
  std::cout << "\n====String: Default Constructor Test====" << std::endl;
  Array<std::string> arr = Array<std::string>();
  if (arr.size() == 0)
    std::cout << "Array is empty as expected" << std::endl;
  else {
    std::cout << "Array is not empty" << std::endl;
    res = 1;
  }
  std::cout << "Array size: " << arr.size() << std::endl;
  std::cout << "\n====String: Copy Constructor Test====" << std::endl;
  Array<std::string> arr1 = Array<std::string>(3);
  arr1[0] = "first";
  arr1[1] = "second";
  arr1[2] = "third";
  Array<std::string> arr2(arr1);
  for (size_t i = 0; i < arr1.size(); i++) {
    if (arr1[i] == arr2[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Constructor Succeeded." << std::endl;
  err = 0;
  std::cout << "\n====String: Copy Assignment Operator Test====" << std::endl;
  arr2[0] = "alpha";
  arr2[1] = "beta";
  arr2[2] = "gamma";
  Array<std::string> arr3 = Array<std::string>(arr2.size());
  arr3 = arr2;
  for (size_t i = 0; i < arr2.size(); i++) {
    if (arr2[i] == arr3[i])
      continue;
    else {
      std::cout << "Copy Failed!" << std::endl;
      err = 1;
      res = 1;
    }
  }
  if (!err)
    std::cout << "Copy Assignment Succeeded." << std::endl;
  std::cout << "\n====String: Empty Array Access====" << std::endl;
  int exception_occurred = 0;
  try {
    arr[0];
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception Did not occurr." << std::endl;
    err = 1;
    res = 1;
  }
  return (res);
}

int subscript_test_string(void) {
  int res = 0;
  int exception_occurred = 0;
  std::cout << "\n====String: Subscript Access====" << std::endl;
  Array<std::string> arr1 = Array<std::string>(3);
  arr1[0] = "hello";
  arr1[1] = "world";
  arr1[2] = "test";
  std::cout << std::endl;
  for (size_t i = 0; i < arr1.size(); i++) {
    std::cout << "arr[" << i << "]: " << arr1[i] << std::endl;
  }
  size_t out_idx = arr1.size();
  try {
    std::cout << arr1[out_idx] << std::endl;
  } catch (const std::exception &e) {
    exception_occurred = 1;
    std::cout << "\nexpected: std::exception\n";
    std::cout << "actual:" << e.what() << std::endl;
  }
  if (exception_occurred == 0) {
    std::cout << "Exception not thrown when index is out of bounds"
              << std::endl;
    res = 1;
  }
  return (res);
}

int main(void)
{
  int ret = 0;
  try {
    if (test_ocf()) {
      std::cout << "\nOCF test failed!" << std::endl;
      ret = 1;
    }
    if (subscript_test()) {
      std::cout << "\nsubscript test failed" << std::endl;
      ret++;
    }
    if (test_ocf_float()) {
      std::cout << "\nFloat OCF test failed!" << std::endl;
      ret++;
    }
    if (subscript_test_float()) {
      std::cout << "\nFloat subscript test failed" << std::endl;
      ret++;
    }
    if (test_ocf_double()) {
      std::cout << "\nDouble OCF test failed!" << std::endl;
      ret++;
    }
    if (subscript_test_double()) {
      std::cout << "\nDouble subscript test failed" << std::endl;
      ret++;
    }
    if (test_ocf_string()) {
      std::cout << "\nString OCF test failed!" << std::endl;
      ret++;
    }
    if (subscript_test_string()) {
      std::cout << "\nString subscript test failed" << std::endl;
      ret++;
    }
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return (ret);
}
