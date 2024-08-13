extern "C" {
	fn reverse_string(s: *mut u8, len: usize);
}

fn main() {
    let mut s = String::from("Rust");
    let len = s.len();
    unsafe {
        reverse_string(s.as_mut_ptr(), len);
    }
    // Convert the modified string back to a Rust string and print it
    println!("The reversed string is {}", s);
}
