use std::slice;
use ripemd::Digest;

#[no_mangle]
pub extern "C" fn ripemd160(input_data: *const u8, length: usize, result: &mut [u8; 20]) {
    assert!(!input_data.is_null());

    let input: &[u8] = unsafe { slice::from_raw_parts(input_data, length) };
    result.copy_from_slice(&ripemd::Ripemd160::digest(input));
}

#[no_mangle]
pub extern "C" fn sha256(input_data: *const u8, length: usize, result: &mut [u8; 32]) {
    assert!(!input_data.is_null());

    let input: &[u8] = unsafe { slice::from_raw_parts(input_data, length) };
    result.copy_from_slice(&sha2::Sha256::digest(input));
}

mod blake2f_impl;

#[no_mangle]
pub extern "C" fn blake2f(input_data: &[u8; 213], result: &mut [u8; 64]) {
   blake2f_impl::blake2f(input_data, result);
}

mod ecdsarecover_impl;

#[no_mangle]
pub extern "C" fn ecdsarecover(hash: &[u8; 32], r: &[u8; 32], s: &[u8; 32], v: u8, result: &mut [u8; 32]) {
    ecdsarecover_impl::ecdsarecover(hash, r, s, v, result);
}
