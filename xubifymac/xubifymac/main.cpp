#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1); // ZeroMQ context oluştur
    zmq::socket_t socket(context, zmq::socket_type::rep); // Sunucu soketi
    socket.bind("tcp://*:5555"); // Bağlantıyı bekle

    while (true) {
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Istemciden Gelen Mesaj: " << request.to_string() << std::endl;

        std::string reply = "sa";
        zmq::message_t response(reply.size());
        memcpy(response.data(), reply.data(), reply.size());
        socket.send(response, zmq::send_flags::none);
    }

    return 0;
}
