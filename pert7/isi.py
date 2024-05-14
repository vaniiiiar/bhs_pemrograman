def display_menu():
    print("Menu:")
    print("1. Pecel Lele - 20,000")
    print("2. Mie Goreng - 15,000")
    print("3. Sambel Lalapan - 10,000")
    print("Minuman:")
    print("4. Teh Manis - 7,000")
    print("5. Teh Tawar - 5,000")
    print("6. Air Putih - 4,000")

def get_price(choice):
    prices = {
        1: 20000,
        2: 15000,
        3: 10000,
        4: 7000,
        5: 5000,
        6: 4000
    }
    return prices.get(choice, 0)

def main():
    total_price = 0
    display_menu()

    try:
        orders = []
        while True:
            choice = int(input("Masukkan pilihan (1-6) atau 0 untuk selesai: "))
            if choice == 0:
                break
            quantity = int(input("Masukkan jumlah: "))
            price_per_unit = get_price(choice)

            if price_per_unit == 0:
                print("Pilihan tidak valid")
                continue

            total_price += price_per_unit * quantity
            orders.append((choice, quantity, price_per_unit * quantity))

        print("\nRincian Pesanan:")
        for order in orders:
            print(f"Item {order[0]} x {order[1]} = {order[2]} IDR")

        print(f"\nTotal Harga: {total_price} IDR")
        print("Proses pembayaran selesai. Terima kasih!")

    except ValueError:
        print("Input tidak valid. Harap masukkan angka.")

if __name__ == "__main__":
    main()
