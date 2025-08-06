//Stern sequence
fn main() {
	//declare an array.size 100000
	const N: usize = 100000;
	let mut arr: [u32; N] = [0; N]; // numbers
	let mut mux: [u16; N] = [0; N]; // max values for [0..n], n - user input

	// generate all numbers and max values on [0..N]
	arr[0] = 0; mux[0] = 0;
	arr[1] = 1; mux[1] = 1;
	let mut max = 1;
	for i in 2..N {
		let val = if i % 2 == 0 {
            arr[i / 2]
        } else {
			let half = i / 2;
            arr[half] + arr[half + 1]
        };
		arr[i] = val;

		if val > max { max = val; }
		mux[i] = max as u16;
	}

	// input the values n.
	loop {
		let n = read_u32();
		if n == 0 { break; }
		println!("{}", mux[n as usize]);
	}
}

fn read_u32() -> u32 {
	let mut input = String::new();
	std::io::stdin().read_line(&mut input).unwrap();
	let n = input.trim_end().parse::<u32>().expect("cannot parse");
	n
}