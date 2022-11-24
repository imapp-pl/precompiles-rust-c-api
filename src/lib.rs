use std::slice;
use ripemd::Digest;

#[no_mangle]
pub extern "C" fn ripemd160(input_data: *const u8, length: usize, mut result: *mut u8) {
    assert!(!input_data.is_null());

    let input: &[u8] = unsafe { slice::from_raw_parts(input_data, length) };
    let mut hash = [0u8; 32];
    hash[12..32].copy_from_slice(&ripemd::Ripemd160::digest(input));
    result = hash.as_mut_ptr();
}
