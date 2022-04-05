import sender
from unittest import mock


class TestSender:
    @mock.patch('sender.random.randint')
    def test_get_a2d_data(self, mock_obj):
        mock_obj.return_value = 2000
        returned_value = sender.get_a2d_data()
        assert returned_value == 2000

    @mock.patch('sender.round')
    def test_convert_a2d_to_amps(self, mock_obj):
        mock_obj.side_effect = [5, 10]  # we use side_effect to raise exception and return different value from
        # same function for each call.
        returned_value = sender.convert_a2d_to_amps(25)
        assert returned_value == 5
        returned_value = sender.convert_a2d_to_amps(521)
        assert returned_value == 10

    @mock.patch('sender.random.randint')
    def test_get_temperature(self, mock_obj):
        mock_obj.return_value = 43
        returned_value = sender.get_temperature()
        assert returned_value == 43

    @mock.patch('sender.get_temperature')
    @mock.patch('sender.convert_a2d_to_amps')
    @mock.patch('builtins.print')
    def test_send_data_to_console(self, mock_obj_print, mock_obj_a2d_to_amps, mock_obj_temp):
        mock_obj_a2d_to_amps.return_value = 10
        mock_obj_temp.return_value = 50
        sender.send_data_to_console()
        mock_obj_print.assert_called_with('Amps: 10, Temp: 50')


if __name__ == "__main__":
    obj = TestSender()
    obj.test_get_a2d_data()
    obj.test_convert_a2d_to_amps()
    obj.test_get_temperature()
    obj.test_send_data_to_console()

