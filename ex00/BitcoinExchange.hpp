#ifndef BTC_HPP
# define BTC_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <utility> // pour utiliser la paire (std::pair)
# include <unistd.h>

#include <map>
#include <stdlib.h>



// +------------------------------------------------------------------------------+
//                                    AFFICHAGE                                   |
// +------------------------------------------------------------------------------+
void                            affichage_map(std::map<std::string, double>  map);

// +------------------------------------------------------------------------------+
//                                    READ_FILE                                   |
// +------------------------------------------------------------------------------+
std::pair<std::string, double>	parse_to_pair (std::string str, char c);
std::map<std::string, double>	open_and_check_conf_file(std::string file, char c);
int				check_valid_format(std::string str);
void	                        serch_and_print(std::map<std::string, double> mapData, std::string file);

// +------------------------------------------------------------------------------+
//                                    VERIF_ARG                                   |
// +------------------------------------------------------------------------------+
void                            check_arg(int argc, char ** argv);

#endif
