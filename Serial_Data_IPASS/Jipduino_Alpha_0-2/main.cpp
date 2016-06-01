#include "hwlib.hpp"

int main(void)
{
       // kill the watchdog    
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    hwlib::wait_ms(1000);
    hwlib::cout << "Starting program...";
    
	auto data_pin_sender = hwlib::target::pin_in_out(0,16);
    auto led_test_program = hwlib::target::pin_in_out(1,21);
    data_pin_sender.direction_set_output();
    led_test_program.direction_set_output();
    
    led_test_program.set(1);
    hwlib::wait_ms(200);
    led_test_program.set(0);
    
    while(1){
    data_pin_sender.set(0);
    auto data = data_pin_sender.get();
    hwlib::cout << "Output A0: " << data << "\n"; 
	}
    return 0;
    
}
