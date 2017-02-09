//
//  ViewController.swift
//  Pic-Key
//
//  Created by Siddharth Patel on 2/8/17.
//  Copyright © 2017 Siddharth Patel. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate {

    var picker: UIImagePickerController!

    @IBOutlet weak var ImageView: UIImageView!
    @IBOutlet weak var ShareButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        Ostetso.showGallery()
        picker = UIImagePickerController();
        picker.delegate = self
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        
        if  let pickedImage = info[UIImagePickerControllerOriginalImage] as? UIImage{
            
            ImageView.image = pickedImage
            ShareButton.isEnabled = true
        }
        dismiss(animated: true, completion: nil)
    }
    
    @IBAction func chooseImageButtonClicked(_ sender: Any) {
        present(self.picker, animated: true, completion: nil)
        
    }
    
    @IBAction func ShareButtonClick(_ sender: Any) {
        
        Ostetso.share(ImageView.image)
        
    }

    
    @IBAction func GalleryBackButtonClicked(_ sender: Any) {
        
        Ostetso.showGallery()
    }

}

