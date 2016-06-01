#include "hwlib.hpp"
#include "signal.hpp"


int main(void)
{
    hwlib::wait_ms(1500);
    hwlib::cout << "Starting.. \n";
    
    auto data_pin_receiver = hwlib::target::pin_in_out(0,16);
    auto led_test_program = hwlib::target::pin_in_out(1,21);
    
    led_test_program.direction_set_output();
    led_test_program.set(1);
    hwlib::wait_ms(200);
    led_test_program.set(0);
    
    signal data(data_pin_receiver/*data_pin_sender*/);
    for(int i = 0; i  < 1; i++){
    hwlib::wait_ms(27);
    data.get_signal();
    data.print_signal();
    }
    return 0;
}