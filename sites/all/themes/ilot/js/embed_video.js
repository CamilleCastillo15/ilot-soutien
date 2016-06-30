(function ($) {
  Drupal.behaviors.embed_video =  {
    attach: function(context, settings) {

      // Ouvrir une video d'actu dans un nouveau onglet

     $('.field-name-field-actualite-video').click(function(){      
        $('embed').attr('src', $('embed').attr('src'));
        var url = $('embed').attr('src');
         window.open(url);
      });

    }
  };
})(jQuery);