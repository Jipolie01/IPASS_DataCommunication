#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#include "hwlib.hpp"

class signal
{
private:
    hwlib::target::pin_in_out data_pin_receiver;
    //hwlib::target::pin_in_out data_pin_sender;
    int counter_nul;
    int data_signal;
public:
    signal(hwlib::target::pin_in_out & data_pin_receiver /*hwlib::target::pin_in_out & data_pin_sender*/):
        data_pin_receiver(data_pin_receiver)
        //data_pin_sender(data_pin_sender)
        {
            counter_nul = 0;
            }
    
    void get_signal(){
        data_pin_receiver.direction_set_input();
        for(int i = 0; i < 25; i++){
            auto data = data_pin_receiver.get();
                if(data == 1){
                    hwlib::wait_ms(2);
                    hwlib::cout << "Output: " << data << "\n";
                }else if(data == 0){
                    hwlib::wait_ms(2);
                    hwlib::cout << "Output: " << data << "\n";
                    counter_nul++;}
        }
        
        if(counter_nul < 19){
            data_signal = 1;
        }else if(counter_nul > 20){
            data_signal = 0;
        }else{
            data_signal = -1;}} 
    
    /*
    void send(bool bit_signal){
        data_pin_sender.direction_set_output();
        data_pin_sender.set(bit_signal);}
    
     */
    void print_signal(){
        if(data_signal == 1){
            hwlib::cout << "Signal = 1 \n";
        }else if(data_signal == 0){
            hwlib::cout << "Signal = 0 \n";
        }else if(data_signal == -1){
            hwlib::cout << "Someting went wrong? \n";
        }
    }
    //virtual void send_byte();
    
};

#endif // SIGNAL_HPP
