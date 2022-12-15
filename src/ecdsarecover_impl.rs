// SPDX-License-Identifier: MIT

pub fn ecdsarecover(hash: &[u8; 32], r: &[u8; 32], s: &[u8; 32], v: u8, result: &mut [u8; 32]) {
    // only 0 and 1 v values are valid
    if v > 1 {
       panic!();
    }

    let mut sig = [0u8; 64];
    sig[0..32].copy_from_slice(&r[..]);
    sig[32..64].copy_from_slice(&s[..]);

    let address = algo::ecdsarecover(&sig, v, &hash)
        .unwrap();
    
    result.copy_from_slice(&address);
}

mod algo {
    use secp256k1::{
        ecdsa::{RecoverableSignature, RecoveryId},
        Message, Secp256k1,
    };
    use sha3::{Digest, Keccak256};

    pub fn ecdsarecover(sig: &[u8; 64], v: u8, msg: &[u8; 32]) -> Result<[u8; 32], secp256k1::Error> {
        let sig =
            RecoverableSignature::from_compact(&sig[0..64], RecoveryId::from_i32(v as i32)?)?;

        let secp = Secp256k1::new();
        let public = secp.recover_ecdsa(&Message::from_slice(&msg[..32])?, &sig)?;

        let hash = Keccak256::digest(&public.serialize_uncompressed()[1..]);
        let mut hash: [u8; 32] = hash[..].try_into().unwrap();

        // erasing first 12 bytes
        hash.iter_mut().take(12).for_each(|i| *i = 0);
        Ok(hash)
    }
}
