import unittest

from calc import calculate

class CalculatorTest(unittest.TestCase):
    def test_addition(self):
        result = calculate(5, 3, '+')
        self.assertEqual(result, 8)

    def test_subtraction(self):
        result = calculate(10, 4, '-')
        self.assertEqual(result, 6)

    def test_multiplication(self):
        result = calculate(2, 6, '*')
        self.assertEqual(result, 12)

    def test_division(self):
        result = calculate(15, 3, '/')
        self.assertEqual(result, 5)

    def test_division_by_zero(self):
        result = calculate(10, 0, '/')
        self.assertEqual(result, "Error: Division by zero")

    def test_invalid_operator(self):
        result = calculate(4, 2, '%')
        self.assertEqual(result, "Error: Invalid operator")

if __name__ == '__main__':
    unittest.main(verbosity=2)
