int x = 5;
int& y = x;

std::cout << x << " " << y << std::endl; `\visible<2->{\tt 5 5}`

x++;

std::cout << x << " " << y << std::endl; `\visible<3->{\tt 6 6}`

y++;

std::cout << x << " " << y << std::endl; `\visible<4->{\tt 7 7}`
