#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.original> <output.h>" << std::endl;
        return 1;
    }

    std::ifstream originalFile(argv[1], std::ios::binary);
    if (!originalFile.is_open()) {
        std::cerr << "Failed to open " << argv[1] << std::endl;
        return 1;
    }

    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(originalFile), {});

    std::ofstream headerFile(argv[2]);
    if (!headerFile.is_open()) {
        std::cerr << "Failed to create " << argv[2] << std::endl;
        return 1;
    }

    headerFile << "#ifndef ARMADA_H\n#define ARMADA_H\n\n";
    headerFile << "unsigned char galleonData[" << buffer.size() << "] = {";
    for (size_t i = 0; i < buffer.size(); ++i) {
        headerFile << "0x" << std::hex << (int)buffer[i];
        if (i < buffer.size() - 1) headerFile << ", ";
        if ((i + 1) % 12 == 0) headerFile << "\n";
    }
    headerFile << "};\n\n";
    headerFile << "#endif // ARMADA_H\n";

    std::cout << "Conversion completed successfully." << std::endl;

    return 0;
}
