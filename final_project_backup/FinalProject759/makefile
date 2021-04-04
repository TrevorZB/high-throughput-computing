all: proofmake serialmake

proofmake: block_header.cpp helpers.cpp mine.cpp proof_of_concept_main.cpp
	g++ -o proof_of_concept block_header.cpp helpers.cpp mine.cpp proof_of_concept_main.cpp

serialmake: block_header.cpp helpers.cpp mine.cpp serial_miner.cpp serial_miner_main.cpp
	g++ -o serial_miner block_header.cpp helpers.cpp mine.cpp serial_miner.cpp serial_miner_main.cpp
