int main(void){
	unsigned int tmp;
	put_s("Welcome\n\r");

	tmp = (unsigned char)dm_read(0x2c);
	print("CHIP Revision 	:", tmp);
	tmp = (unsigned char)dm_read(0x28);
	print("Vendor ID_L 	:", tmp);
	tmp = (unsigned char)dm_read(0x29);
	print("Vendor ID_H 	:", tmp);
	tmp = (unsigned char)dm_read(0x2a);
	print("Product ID_L 	:", tmp);
	tmp = (unsigned char)dm_read(0x2b);
	print("Product ID_H 	:", tmp);

	return 0;
}
